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
 * compile-time check if a float is +/-Inf
 */

#ifndef _gcem_is_inf_HPP
#define _gcem_is_inf_HPP

/**
 * Compile-time check if a float is -Inf
 *
 * @param x floating point value.
 * @return true if \c x is -Inf, false otherwise.
 */

template<typename T>
constexpr
bool
is_neginf(const T x)
noexcept
{
    return x == - GCLIM<T>::infinity();
}

/**
 * Compile-time check if a float is -Inf
 *
 * @param x floating point value.
 * @return true if \c x is -Inf, false otherwise.
 */

template<typename T>
constexpr
bool
any_neginf(const T x)
noexcept
{
    return is_neginf(x);
}

/**
 * Compile-time check if any float in a sequence is -Inf
 *
 * @param args... floating point values.
 * @return true if any float in a sequence is -Inf, false otherwise.
 */

template<typename T, typename... Args>
constexpr
bool
any_neginf(const T x, const Args... args)
noexcept
{
    return is_neginf(x) || is_neginf(args...);
}

/**
 * Compile-time check if a float is -Inf
 *
 * @param x floating point value.
 * @return true if \c x is -Inf, false otherwise.
 */

template<typename T>
constexpr
bool
all_neginf(const T x)
noexcept
{
    return is_neginf(x);
}

/**
 * Compile-time check if all floats in a sequence are -Inf
 *
 * @param args... floating point values.
 * @return true if all floats in a sequence are -Inf, false otherwise.
 */

template<typename T, typename... Args>
constexpr
bool
all_neginf(const T x, const Args... args)
noexcept
{
    return is_neginf(x) && all_neginf(args...);
}

//

/**
 * Compile-time check if a float is +Inf
 *
 * @param x floating point value.
 * @return true if \c x is +Inf, false otherwise.
 */

template<typename T>
constexpr
bool
is_posinf(const T x)
noexcept
{
    return x == GCLIM<T>::infinity();
}

/**
 * Compile-time check if a float is +Inf
 *
 * @param x floating point value.
 * @return true if \c x is +Inf, false otherwise.
 */

template<typename T>
constexpr
bool
any_posinf(const T x)
noexcept
{
    return is_posinf(x);
}

/**
 * Compile-time check if any float in a sequence is +Inf
 *
 * @param args... floating point values.
 * @return true if any float in a sequence is +Inf, false otherwise.
 */

template<typename T, typename... Args>
constexpr
bool
any_posinf(const T x, const Args... args)
noexcept
{
    return is_posinf(x) || any_posinf(args...);
}

/**
 * Compile-time check if a float is +Inf
 *
 * @param x floating point value.
 * @return true if \c x is +Inf, false otherwise.
 */

template<typename T>
constexpr
bool
all_posinf(const T x)
noexcept
{
    return is_posinf(x);
}

/**
 * Compile-time check if all floats in a sequence are +Inf
 *
 * @param args... floating point values.
 * @return true if all floats in a sequence are +Inf, false otherwise.
 */


template<typename T, typename... Args>
constexpr
bool
all_posinf(const T x, const Args... args)
noexcept
{
    return is_posinf(x) && all_posinf(args...);
}

//

/**
 * Compile-time check if a float is +/-Inf
 *
 * @param x floating point value.
 * @return true if \c x is +/-Inf, false otherwise.
 */

template<typename T>
constexpr
bool
is_inf(const T x)
noexcept
{
    return is_neginf(x) || is_posinf(x);
}

/**
 * Compile-time check if a float is +/-Inf
 *
 * @param x floating point value.
 * @return true if \c x is +/-Inf, false otherwise.
 */

template<typename T>
constexpr
bool
any_inf(const T x)
noexcept
{
    return is_inf(x);
}

/**
 * Compile-time check if any float in a sequence is +/-Inf
 *
 * @param args... floating point values.
 * @return true if any float in a sequence is +/-Inf, false otherwise.
 */

template<typename T, typename... Args>
constexpr
bool
any_inf(const T x, const Args... args)
noexcept
{
    return is_inf(x) || any_inf(args...);
}

/**
 * Compile-time check if a float is +/-Inf
 *
 * @param x floating point value.
 * @return true if \c x is +/-Inf, false otherwise.
 */

template<typename T>
constexpr
bool
all_inf(const T x)
noexcept
{
    return is_inf(x);
}

/**
 * Compile-time check if all floats in a sequence are +/-Inf
 *
 * @param args... floating point values.
 * @return true if all floats in a sequence are +/-Inf, false otherwise.
 */

template<typename T, typename... Args>
constexpr
bool
all_inf(const T x, const Args... args)
noexcept
{
    return is_inf(x) && all_inf(args...);
}

#endif
