/*******************************************************************************
 * Name            : eraser_tool.cc
 * Project         : BrushWork
 * Description     : .cc file for EraserTool class
 * Copyright	   : 2016 Andrew, Derek, Michael
 * Creation Date   : 10/10/16
 * Original Author : Andrew B., Derek G., Michael M.
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "include/eraser_tool.h"

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/

namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
EraserTool::EraserTool(void) : DrawingTool() {
  center_x_ = 10;
  center_y_ = 10;
  mask_width_ = 21;
  mask_height_ = 21;
  mask_ = new float*[mask_width_];
  float distance_ = 0.0;

  for (int i = 0; i < mask_width_; i++) {
    mask_[i] = new float[mask_height_];
    for (int j = 0; j < mask_height_; j++) {
      distance_ = sqrt(pow(j - center_x_, 2.0) + pow(i - center_y_, 2.0));
      if (distance_ >= 10.0) {
        mask_[i][j] = 0.0;
      } else {
        mask_[i][j] = 1.0;
      }
    }
  }
}


EraserTool::~EraserTool(void) {
}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void EraserTool::ApplyToCanvas
(int x, int y, PixelBuffer* display_buffer_, ColorData color) {
  // Set x and y to the coordinates of the top left pixel of mask_
  x -= center_x_;
  y -= center_y_;
  float transparency = 0.0;

  for (int i = 0; i < mask_height_; i++) {
    for (int j = 0; j < mask_width_; j++) {
      ColorData cur_canvas_col = display_buffer_->background_color();
      transparency = mask_[i][j];
      if (transparency == 1.0) {
        display_buffer_->set_pixel(x+i, y+j, (cur_canvas_col * transparency));
      }
    }
  }
}


}  // namespace image_tools
