/**
 * Copyright 2017, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *
 *     * Neither the name of the copyright holder nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "KVStoreBaseImpl.h"
#include <FogKV/Types.h>

#include "common.h"

namespace FogKV {

KVStoreBase *KVStoreBase::Open(const Options &options, Status *status)
{
	return KVStoreBaseImpl::Open(options, status);
}

KVStoreBase *KVStoreBaseImpl::Open(const Options &options, Status *status)
{
	KVStoreBaseImpl *kvs = new KVStoreBaseImpl(options);

	*status = kvs->init();
	if (status->ok())
		return dynamic_cast<KVStoreBase *>(kvs);

	delete kvs;

	return nullptr;
}

KVStoreBaseImpl::KVStoreBaseImpl(const Options &options)
{
}

KVStoreBaseImpl::~KVStoreBaseImpl()
{
}

std::string KVStoreBaseImpl::getProperty(const std::string &name)
{
	throw FUNC_NOT_IMPLEMENTED;
}

size_t KVStoreBaseImpl::KeySize()
{
	throw FUNC_NOT_IMPLEMENTED;
}

const Options & KVStoreBaseImpl::getOptions()
{
	throw FUNC_NOT_IMPLEMENTED;
}

Status KVStoreBaseImpl::Put(const char *key, const char *value, size_t size)
{
	throw FUNC_NOT_IMPLEMENTED;
}

Status KVStoreBaseImpl::Put(const char *key, KVBuff *buff)
{
	throw FUNC_NOT_IMPLEMENTED;
}

Status KVStoreBaseImpl::PutAsync(const char *key, const char *value, size_t size, KVStoreBaseCallback cb)
{
	throw FUNC_NOT_IMPLEMENTED;
}

Status KVStoreBaseImpl::PutAsync(const char *key, KVBuff *buff, KVStoreBaseCallback cb)
{
	throw FUNC_NOT_IMPLEMENTED;
}

Status KVStoreBaseImpl::Get(const char *key, char *value, size_t *size)
{
	throw FUNC_NOT_IMPLEMENTED;
}

Status KVStoreBaseImpl::Get(const char *key, std::vector<char> &value)
{
	throw FUNC_NOT_IMPLEMENTED;
}

Status KVStoreBaseImpl::Get(const char *key, KVBuff *buff)
{
	throw FUNC_NOT_IMPLEMENTED;
}

Status KVStoreBaseImpl::Get(const char *key, KVBuff **buff)
{
	throw FUNC_NOT_IMPLEMENTED;
}

Status KVStoreBaseImpl::GetAsync(const char *key, KVStoreBaseCallback cb)
{
	throw FUNC_NOT_IMPLEMENTED;
}

Status KVStoreBaseImpl::GetRange(const char *beg, const char *end, std::vector<KVPair> &result)
{
	throw FUNC_NOT_IMPLEMENTED;
}

Status KVStoreBaseImpl::GetRangeAsync(const char *beg, const char *end, KVStoreBaseRangeCallback cb)
{
	throw FUNC_NOT_IMPLEMENTED;
}

KVBuff *KVStoreBaseImpl::Alloc(size_t size, const AllocOptions &options)
{
	throw FUNC_NOT_IMPLEMENTED;
}

void KVStoreBaseImpl::Free(KVBuff *buff)
{
	throw FUNC_NOT_IMPLEMENTED;
}

KVBuff *KVStoreBaseImpl::Realloc(KVBuff *buff, size_t size, const AllocOptions &options)
{
	throw FUNC_NOT_IMPLEMENTED;
}

Status KVStoreBaseImpl::Remove(const char *key)
{
	throw FUNC_NOT_IMPLEMENTED;
}

Status KVStoreBaseImpl::RemoveRange(const char *beg, const char *end)
{
	throw FUNC_NOT_IMPLEMENTED;
}

Status KVStoreBaseImpl::init()
{
	return NotImplemented;
}

} // namespace FogKV