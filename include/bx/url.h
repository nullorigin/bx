/*
 * Copyright 2010-2017 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bx#license-bsd-2-clause
 */

#ifndef BX_URL_H_HEADER_GUARD
#define BX_URL_H_HEADER_GUARD

#include "string.h"

namespace bx
{
	///
	struct UrlToken
	{
		enum Enum
		{
			Scheme,
			UserName,
			Password,
			Host,
			Port,
			Path,
			Query,
			Fragment,

			Count
		};
	};

	///
	class UrlView
	{
	public:
		///
		UrlView();

		///
		void clear();

		///
		bool parse(const StringView& _url);

		///
		const StringView& get(UrlToken::Enum _token) const;

	private:
		StringView m_tokens[UrlToken::Count];
	};

	///
	void urlEncode(const char* _str, char* _buf, uint32_t _bufSize);

} // namespace bx

#endif // BX_URL_H_HEADER_GUARD
