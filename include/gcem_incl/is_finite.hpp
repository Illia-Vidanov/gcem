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
 * compile-time check if a float is not NaN-valued or +/-Inf
 */

#ifndef _gcem_is_finite_HPP
#define _gcem_is_finite_HPP

/**
 * Compile-time check if a float is not NaN-valued or +/-Inf
 *
 * @param x floating point value.
 * @return true if \c x is not NaN-valued or +/-Inf, false otherwise.
 */

template<typename T>
constexpr
bool
is_finite(const T x)
noexcept
{
    return (!is_nan(x)) && (!is_inf(x));
}

/**
 * Compile-time check if a float is not NaN-valued or +/-Inf
 *
 * @param x floating point value.
 * @return true if \c x is not NaN-valued or +/-Inf, false otherwise.
 */

template<typename T>
constexpr
bool
any_finite(const T x)
noexcept
{
    return is_finite(x);
}

/**
 * Compile-time check if any float in a sequence is not NaN-valued or +/-Inf
 *
 * @param args... floating point values.
 * @return true if any float in a sequence is not NaN-valued or +/-Inf, false otherwise.
 */

template<typename T, typename... Args>
constexpr
bool
any_finite(const T x, const Args... args)
noexcept
{
    return is_finite(x) || any_finite(args...);
}

/**
 * Compile-time check if a float is not NaN-valued or +/-Inf
 *
 * @param x floating point value.
 * @return true if \c x is not NaN-valued or +/-Inf, false otherwise.
 */

template<typename T>
constexpr
bool
all_finite(const T x)
noexcept
{
    return is_finite(x);
}

/**
 * Compile-time check if all floats in a sequence are not NaN-valued or +/-Inf
 *
 * @param args... floating point values.
 * @return true if all floats in a sequence are not NaN-valued or +/-Inf, false otherwise.
 */

template<typename T, typename... Args>
constexpr
bool
all_finite(const T x, const Args... args)
noexcept
{
    return is_finite(x) && all_finite(args...);
}

#endif
