/*******************************************************************************
 * Name            : highlighter_tool.cc
 * Project         : BrushWork
 * Description     : .cc file for HighlighterTool class
 * Copyright	   : 2016 Andrew, Derek, Michael
 * Creation Date   : 10/17/16
 * Original Author : Andrew B., Derek G., Michael M.
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/highlighter_tool.h"
#include "include/drawing_tool.h"


/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/

namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
HighlighterTool::HighlighterTool(void) : DrawingTool() {
  int apply_ = 0;
  center_x_ = 2;
  center_y_ = 7;
  mask_width_ = 15;
  mask_height_ = 5;

  // initialize the mask for the highlighter tool, which is a 15x5 rectangle
  // that mimics the real behavior a highlighter
  mask_ = new float* [mask_height_];

  for (int i = 0; i < mask_height_; i++) {
    mask_[i] = new float[mask_width_];
    for (int j = 0; j < mask_width_; j++) {
      mask_[i][j] = 0.4;
    }
  }
}

HighlighterTool::~HighlighterTool(void) {
}

// this method overrides the method from the DrawingTool base class,
// because it limits the amount of
// times that the highlighter applies itself to the canvas
void HighlighterTool::ApplyToCanvas
(int x, int y, PixelBuffer* display_buffer_, ColorData color) {
  if (apply_ > 0) {
    apply_ -= 1;
  } else {
    // Set x and y to the coordinates of the top left pixel of mask_
    x -= center_x_;
    y -= center_y_;
    float transparency = 0.0;

    for (int i = 0; i < mask_height_; i++) {
      for (int j = 0; j < mask_width_; j++) {
        ColorData cur_canvas_col = display_buffer_->get_pixel(x+i, y+j);

        transparency = mask_[i][j];

        if (transparency > 0.0 && transparency < 1.0) {
          transparency = mask_[i][j]*cur_canvas_col.luminance();
        }

        display_buffer_->set_pixel(x+i, y+j, (cur_canvas_col *
        (1.0 - transparency)) + (color * transparency));
      }
    }
    apply_ += 4;
  }
}
}  // namespace image_tools
