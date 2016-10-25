/*******************************************************************************
 * Name            : calligraphy_tool.h
 * Project         : BrushWork
 * Description     : Header file for CalligraphyTool class
 * Copyright	   : 2016 Andrew, Derek, Michael
 * Creation Date   : 10/10/16
 * Original Author : Andrew B., Derek G., Michael M.
 ******************************************************************************/
#ifndef INCLUDE_PEN_TOOL_H_
#define INCLUDE_PEN_TOOL_H_
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
class PenTool : public DrawingTool {
 public:
  PenTool(void);
  ~PenTool(void);

 private:
};
}  // namespace image_tools
#endif  // INCLUDE_PEN_TOOL_H_
