/*******************************************************************************
 * Name            : spray_can_tool.h
 * Project         : BrushWork
 * Description     : Header file for SprayCanTool class
 * Copyright	   : 2016 Andrew, Derek, Michael
 * Creation Date   : 10/17/16
 * Original Author : Andrew B., Derek G., Michael M.
 *
 ******************************************************************************/
#ifndef INCLUDE_SPRAY_CAN_TOOL_H_
#define INCLUDE_SPRAY_CAN_TOOL_H_
#include <cmath>
#include <iostream>
#include "include/drawing_tool.h"
#include "include/color_data.h"
#include "include/pixel_buffer.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class SprayCanTool : public DrawingTool {
 public:
  SprayCanTool(void);
  ~SprayCanTool(void);
  // this function is going to override the ApplyToCanvas function
  // from DrawingTool because we want to limit the
  // amount of times the SprayCanTool applies itslef to the canvas
  void ApplyToCanvas(
    int x,
    int y,
    PixelBuffer* display_buffer_,
    ColorData color);

 private:
  // aplly_ willl act as a boolean value in ApplyToCanvas
  int apply_;
};
}  // namespace image_tools
#endif  // INCLUDE_SPRAY_CAN_TOOL_H_
