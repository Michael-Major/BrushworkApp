/*******************************************************************************
 * Name            : calligraphy_tool.cc
 * Project         : BrushWork
 * Description     : .cc file for CalligraphyTool class
 * Copyright	   : 2016 Andrew, Derek, Michael
 * Creation Date   : 10/17/16
 * Original Author : Andrew B., Derek G., Michael M.
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/calligraphy_tool.h"


/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/

namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
CalligraphyTool::CalligraphyTool(void) : DrawingTool() {
  center_x_ = 2;
  center_y_ = 7;
  mask_width_ = 15;
  mask_height_ = 5;
  mask_ = new float*[mask_height_];

  for (int i = 0; i < mask_height_; i++) {
    mask_[i] = new float[mask_width_];
    for (int j = 0; j < mask_width_; j++) {
      mask_[i][j] = 1;
    }
  }
}


CalligraphyTool::~CalligraphyTool(void) {
}
}  // namespace image_tools
