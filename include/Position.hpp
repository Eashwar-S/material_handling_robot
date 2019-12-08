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
 * @file Position.hpp
 *
 * @author Akwasi A Obeng(Driver)  Eashwar Sathyamurthy(Navigator)
 *
 * @brief declaration for Position class
 *
 * @version 1
 *
 * @date 2019-12-06
 *
 * This .hpp file has declarations for the class attributes and methods for
 * simple functionality of positioning the markers in the turtlebot world.
 *
 */
/**
 *
 * @brief declaration of Position class
 *
 */
#ifndef SRC_MATERIAL_HANDLING_ROBOT_INCLUDE_POSITION_HPP_
#define SRC_MATERIAL_HANDLING_ROBOT_INCLUDE_POSITION_HPP_

class Position {
 private:
  float x, y;

 public:
  /**
   *
   * @brief parameterized constructor to initialize the private members
   *
   * @param x specifies x-coordinate of the marker
   * 
   * @param y specifies y-coordinate of the marker
   *
   * @return none
   *
   */
  Position(float x, float y);
  /**
   *
   * @brief destructor to destroy the Position class object
   *
   * @param none
   *
   * @return none
   *
   */
  ~Position();
  /**
   * @brief getter method to get the y-coordinate of the marker
   *
   * @param none
   *
   * @return float y-coordinate of the marker
   *
   */
  float getY();
  /**
   * @brief getter method to get the x-coordinate of the marker
   *
   * @param none
   *
   * @return float x-coordinate of the marker
   * 
   */
  float getX();
};
#endif  // SRC_MATERIAL_HANDLING_ROBOT_INCLUDE_POSITION_HPP_
