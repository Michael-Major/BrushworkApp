/*******************************************************************************
 * Name            : caligraphy_tool.h
 * Project         : BrushWork
 * Description     : Header file for CaligraphyTool class
 * Copyright	   : 2016 Andrew, Derek, Michael
 * Creation Date   : 10/10/16
 * Original Author : Andrew B., Derek G., Michael M.
 ******************************************************************************/
#ifndef INCLUDE_SPOKE_TOOL_H_
#define INCLUDE_SPOKE_TOOL_H_
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
class SpokeTool : public DrawingTool {
 public:
  SpokeTool(void);
  ~SpokeTool(void);

 private:
};
}  // namespace image_tools
#endif  // INCLUDE_SPOKE_TOOL_H_
