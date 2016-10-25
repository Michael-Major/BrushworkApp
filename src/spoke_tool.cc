/*******************************************************************************
 * Name            : spoke_tool.cc
 * Project         : BrushWork
 * Description     : .cc file for SpokeTool class
 * Copyright	   : 2016 Andrew, Derek, Michael
 * Creation Date   : 10/10/16
 * Original Author : Andrew B., Derek G., Michael M.
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/spoke_tool.h"

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/

namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
SpokeTool::SpokeTool(void) : DrawingTool() {
  center_x_ = 1;
  center_y_ = 1;
  mask_width_ = 3;
  mask_height_ = 3;

  // initialize the mask for the spoke tool, which is a 3x3 square
  mask_ = new float* [3];

  for (int i = 0; i < mask_width_; i++) {
    mask_[i] = new float[3];
  }
  mask_[0][0] = 1.0;
  mask_[0][1] = 1.0;
  mask_[0][2] = 1.0;
  mask_[1][0] = 1.0;
  mask_[1][1] = 1.0;
  mask_[1][2] = 1.0;
  mask_[2][0] = 1.0;
  mask_[2][1] = 1.0;
  mask_[2][2] = 1.0;
}


SpokeTool::~SpokeTool(void) {
}



/*******************************************************************************
 * Member Functions
 ******************************************************************************/

}  // namespace image_tools
