/*################################################################################
  ##
  ##   Copyright (C) 2016-2024 Keith O'Hara
  ##
  ##   This file is part of the GCE-Math C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

/*
 * compile-time check if a float is NaN-valued
 */

#ifndef _gcem_is_nan_HPP
#define _gcem_is_nan_HPP

// future: consider using __builtin_isnan(__x)

/**
 * Compile-time check if a float is NaN-valued
 *
 * @param x floating point value.
 * @return true if \c x is NaN-valued, false otherwise.
 */

template<typename T>
constexpr
bool
is_nan(const T x)
noexcept
{
    return x != x;
}

/**
 * Compile-time check if a float is NaN-valued
 *
 * @param x floating point value.
 * @return true if \c x is NaN-valued, false otherwise.
 */

template<typename T, typename... Args>
constexpr
bool
any_nan(const T x)
noexcept
{
    return is_nan(x);
}

/**
 * Compile-time check if any float in a sequence is NaN-valued
 *
 * @param args... floating point values.
 * @return true if any float in a sequence is NaN-valued, false otherwise.
 */

template<typename T, typename... Args>
constexpr
bool
any_nan(const T x, const Args... args)
noexcept
{
    return is_nan(x) || any_nan(args...);
}

/**
 * Compile-time check if a float is NaN-valued
 *
 * @param x floating point value.
 * @return true if \c x is NaN-valued, false otherwise.
 */

template<typename T, typename... Args>
constexpr
bool
all_nan(const T x)
noexcept
{
    returnis_nan(x);
}

/**
 * Compile-time check if all floats in a sequence are NaN-valued
 *
 * @param args... floating point values.
 * @return true if all floats in a sequence are NaN-valued, false otherwise.
 */

template<typename T, typename... Args>
constexpr
bool
all_nan(const T x, const Args... args)
noexcept
{
    return is_nan(x) && all_nan(args...);
}

#endif
