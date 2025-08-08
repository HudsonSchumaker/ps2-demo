/**
* @file Dimension.h
* @author Hudson Schumaker
* @brief Defines the Dimension class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#pragma once

/**
* @brief A template struct that represents a dimension with width and height.
* @tparam T The type of the width and height. Can be any numeric type (int, float, double, etc.).
*/
template <typename T>
class Dimension final {
public:
    T w = 0;  ///< The width of the dimension.
    T h = 0;  ///< The height of the dimension.

    /**
    * @brief Default constructor. Initializes width and height to 0.
    */
    Dimension() {}

    /**
    * @brief Parameterized constructor. Initializes width and height to the provided values.
    *
    * @param w The width of the dimension.
    * @param h The height of the dimension.
    */
    Dimension(T w, T h) : w(w), h(h) {}

    /**
    * @brief Default destructor.
    */
    ~Dimension() = default;
};
