/**
 * Copyright 2018 Intel Corporation.
 *
 * This software and the related documents are Intel copyrighted materials,
 * and your use of them is governed by the express license under which they
 * were provided to you (Intel OBL Internal Use License).
 * Unless the License provides otherwise, you may not use, modify, copy,
 * publish, distribute, disclose or transmit this software or the related
 * documents without Intel's prior written permission.
 *
 * This software and the related documents are provided as is, with no
 * express or implied warranties, other than those that are expressly
 * stated in the License.
 */

#include <functional>

#include <boost/assign/list_of.hpp>
#include <boost/program_options.hpp>

#include "config.h"
#include "debug.h"
#include "tests/tests.h"
#include <daqdb/KVStoreBase.h>

using namespace std;

namespace po = boost::program_options;

static void initLogger() {
    logging::add_console_log(std::clog, keywords::format = "%Message%");
    logging::add_common_attributes();
    logging::core::get()->add_thread_attribute("Scope", attrs::named_scope());
    logging::core::get()->set_filter(logging::trivial::severity >=
                                     logging::trivial::debug);
}

static bool executeTest(string test, function<bool(DaqDB::KVStoreBase *)> fn,
                        DaqDB::KVStoreBase *kvs) {
    LOG_INFO << string(80, '-') << endl << test << endl << string(80, '-');

    if (fn(kvs)) {
        LOG_INFO << "Test completed successfully" << endl;
        return true;
    } else {
        LOG_INFO << "Test failed" << endl;
        return false;
    }
}

int main(int argc, const char *argv[]) {
    string configFile;

    initLogger();

    po::options_description argumentsDescription{"Options"};
    argumentsDescription.add_options()("help,h", "Print help messages")(
        "config-file,c",
        po::value<string>(&configFile)->default_value("functests_thin.cfg"),
        "Configuration file");

    po::variables_map parsedArguments;
    try {
        po::store(po::parse_command_line(argc, argv, argumentsDescription),
                  parsedArguments);

        if (parsedArguments.count("help")) {
            std::cout << argumentsDescription << endl;
            return 0;
        }
        po::notify(parsedArguments);
    } catch (po::error &parserError) {
        cerr << "Invalid arguments: " << parserError.what() << endl << endl;
        cerr << argumentsDescription << endl;
        return -1;
    }

    LOG_INFO << "Functional tests for DAQDB (thin) library" << flush;

    DaqDB::Options options;
    initKvsOptions(options, configFile);

    unique_ptr<DaqDB::KVStoreBase> spKVStore;
    try {
        spKVStore.reset(DaqDB::KVStoreBase::Open(options));
    } catch (DaqDB::OperationFailedException &e) {
        LOG_INFO << "Failed to create KVStore: " << e.what() << endl;
        return -1;
    }

    map<string, function<bool(DaqDB::KVStoreBase *)>> tests =
        boost::assign::map_list_of("test_remote_peer_connect",
                                   testRemotePeerConnect)(
            "test_put_gate_sequence", testPutGetSequence);

    unsigned short failsCount = 0;
    for (auto test : tests) {
        if (!executeTest(test.first, test.second, spKVStore.get())) {
            failsCount++;
        }
    }

    if (failsCount > 0) {
        LOG_INFO << format("Test(s) failed [%1%]") % failsCount << endl;
    } else {
        LOG_INFO << "All tests passed!" << endl;
    }
}