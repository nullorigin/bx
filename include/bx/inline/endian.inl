/*
 * Copyright 2010-2024 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bx/blob/master/LICENSE
 */
#pragma once
#include "bx/endian.hpp"
#include <cassert>
#include <cstdint>
#ifndef BX_ENDIAN_H_HEADER_GUARD
#	error "Must be included from bx/endian.hpp!"
#endif // BX_ENDIAN_H_HEADER_GUARD

namespace bx {
inline uint8_t endianSwap_u8(uint8_t _in) { return _in; }
inline int8_t endianSwap_s8(int8_t _in) { return (int8_t)endianSwap_u8((uint8_t)_in); }
	inline int16_t endianSwap_s16(int16_t _in)
	{
		return (int16_t)endianSwap_u16((uint16_t)_in);
	}
	inline uint16_t endianSwap_u16(uint16_t _in)
	{
		return (_in>>8) | (_in<<8);
	}

	inline int32_t endianSwap_s32(int32_t _in)
	{
		return (int32_t)endianSwap_u32((uint32_t)_in);
	}

	inline uint32_t endianSwap_u32(uint32_t _in)
	{
		return (  _in            >>24) | (  _in            <<24)
			 | ( (_in&0x00ff0000)>> 8) | ( (_in&0x0000ff00)<< 8)
			 ;
	}

	inline int64_t endianSwap_s64(int64_t _in)
	{
		return (int64_t)endianSwap_u64( (uint64_t)_in);
	}

	inline uint64_t endianSwap_u64(uint64_t _in)
	{
		return   (_in                               >>56) | (  _in                               <<56)
			 | ( (_in&UINT64_C(0x00ff000000000000) )>>40) | ( (_in&UINT64_C(0x000000000000ff00) )<<40)
			 | ( (_in&UINT64_C(0x0000ff0000000000) )>>24) | ( (_in&UINT64_C(0x0000000000ff0000) )<<24)
			 | ( (_in&UINT64_C(0x000000ff00000000) )>> 8) | ( (_in&UINT64_C(0x00000000ff000000) )<< 8)
			 ;
	}
        template <typename T> inline T endianSwap(const T &_in) {
          switch (sizeof(_in)) {
            case 1: return (T)endianSwap_s8(_in);
            case 2: return (T)endianSwap_s16(_in);
            case 4: return (T)endianSwap_s32(_in);
            case 8: return (T)endianSwap_s64(_in);
            default: assert(false); return 0;
          }
			}
	template <typename Ty>
	inline Ty toLittleEndian(Ty _in)
	{
#if BX_CPU_ENDIAN_BIG
		return endianSwap(_in);
#else
		return _in;
#endif // BX_CPU_ENDIAN_BIG
	}

	template <typename Ty>
	inline Ty toBigEndian(Ty _in)
	{
#if BX_CPU_ENDIAN_LITTLE
		return endianSwap(_in);
#else
		return _in;
#endif // BX_CPU_ENDIAN_LITTLE
	}

	template <typename Ty>
	inline Ty toHostEndian(Ty _in, bool _fromLittleEndian)
	{
#if BX_CPU_ENDIAN_LITTLE
		return _fromLittleEndian ? _in : endianSwap_s16(_in);
#else
		return _fromLittleEndian ? endianSwap(_in) : _in;
#endif // BX_CPU_ENDIAN_LITTLE
	}

} // namespace bx
