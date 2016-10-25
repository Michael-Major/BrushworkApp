/*******************************************************************************
 * Name            : drawing_tool.h
 * Project         : BrushWork
 * Description     : Header file for DrawingTool class
 * Copyright	   : 2016 Andrew, Derek, Michael
 * Creation Date   : 10/5/16
 * Original Author : Andrew B., Derek G., Michael M.
 *
 ******************************************************************************/

#ifndef INCLUDE_DRAWING_TOOL_H_
#define INCLUDE_DRAWING_TOOL_H_
#include <iostream>
#include <cmath>
#include "include/color_data.h"
#include "include/pixel_buffer.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class PixelBuffer;
class ColorData;

class DrawingTool {
 public:
  DrawingTool(void);
  virtual ~DrawingTool(void);
  virtual void ApplyToCanvas(
    int x,
    int y,
    PixelBuffer* display_buffer_,
    ColorData color);
  inline virtual int GetWidth() { return mask_width_; }
  inline virtual int GetHeight() { return mask_height_; }

 protected:
  int mask_width_;
  int mask_height_;
  int center_x_;
  int center_y_;
  float ** mask_;
};
}  // namespace image_tools
#endif  // INCLUDE_DRAWING_TOOL_H_
