/******************************************************************************
 * Name            : eraser_tool.h
 * Project         : BrushWork
 * Description     : Header file for EraserTool class
 * Copyright	   : 2016 Andrew, Derek, Michael
 * Creation Date   : 10/10/16
 * Original Author : Andrew B., Derek G., Michael M.
 ******************************************************************************/
#ifndef INCLUDE_ERASER_TOOL_H_
#define INCLUDE_ERASER_TOOL_H_
#include <iostream>
#include <cmath>
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
class EraserTool : public DrawingTool {
 public:
  EraserTool(void);
  ~EraserTool(void);
void ApplyToCanvas(int x, int y, PixelBuffer* display_buffer_, ColorData color);

 private:
};

}  // namespace image_tools

#endif  // INCLUDE_ERASER_TOOL_H_
