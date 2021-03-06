// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SVGRootPainter_h
#define SVGRootPainter_h

#include "platform/wtf/Allocator.h"

namespace blink {

struct PaintInfo;
class AffineTransform;
class IntRect;
class LayoutPoint;
class LayoutSVGRoot;

class SVGRootPainter {
  STACK_ALLOCATED();

 public:
  SVGRootPainter(const LayoutSVGRoot& layout_svg_root)
      : layout_svg_root_(layout_svg_root) {}

  void PaintReplaced(const PaintInfo&, const LayoutPoint&);

  // The embedded SVG document uses an unsnapped viewport box for layout, while
  // SVG root's border box ultimately gets snapped during paint. This
  // translate/scale transform is applied to compensate the difference, in
  // addition to applying the local to border box transform.
  AffineTransform TransformToPixelSnappedBorderBox(
      const LayoutPoint& paint_offset) const;

 private:
  IntRect PixelSnappedSize(const LayoutPoint& paint_offset) const;

  const LayoutSVGRoot& layout_svg_root_;
};

}  // namespace blink

#endif  // SVGRootPainter_h
