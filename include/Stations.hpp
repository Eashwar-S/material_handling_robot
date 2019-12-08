/******************************************************************************
 * MIT License
 *
 * Copyright (c) 2019 Akwasi A Obeng and Eashwar Sathyamurthy
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * @file Stations.hpp
 *
 * @author Akwasi A Obeng(Driver)  Eashwar Sathyamurthy(Navigator)
 *
 * @brief declaration for Stations class
 *
 * @version 1
 *
 * @date 2019-12-06
 *
 * This .hpp file has declarations for the class attributes and methods for
 * simple functionality of positioning the markers in the turtlebot world.
 *
 */

#include <vector>
#include "Position.hpp"

#ifndef SRC_MATERIAL_HANDLING_ROBOT_INCLUDE_STATIONS_HPP_
#define SRC_MATERIAL_HANDLING_ROBOT_INCLUDE_STATIONS_HPP_
/**
 *
 * @brief declaration of Stations class
 *
 */
class Stations {
 private:
  std::vector<Position> stations;

 public:
  /**
   *
   * @brief default constructor to initialize the private members
   *
   * @param none
   *
   * @return none
   *
   */
  Stations();
  /**
   *
   * @brief destructor to destroy the Stations class object
   *
   * @param none
   *
   * @return none
   *
   */
  ~Stations();
  /**
   * @brief Used to give vector of positions
   *
   * @param none
   *
   * @return vector<Position>& a reference to a vector of positions
   *
   */
  std::vector<Position>& getStations();
};
#endif  // SRC_MATERIAL_HANDLING_ROBOT_INCLUDE_STATIONS_HPP_

