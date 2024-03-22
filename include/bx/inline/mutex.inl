/*
 * Copyright 2010-2024 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bx/blob/master/LICENSE
 */
#pragma once
#include "bx/mutex.hpp"
#ifndef BX_MUTEX_H_HEADER_GUARD
#	error "Must be included from bx/mutex.hpp!"
#endif // BX_MUTEX_H_HEADER_GUARD

namespace bx
{
	inline MutexScope::MutexScope(Mutex& _mutex)
		: m_mutex(_mutex)
	{
		m_mutex.lock();
	}

	inline MutexScope::~MutexScope()
	{
		m_mutex.unlock();
	}

} // namespace bx
