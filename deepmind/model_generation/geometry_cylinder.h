// Copyright (C) 2017 Google Inc.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef DML_DEEPMIND_MODEL_GENERATION_GEOMETRY_CYLINDER_H_
#define DML_DEEPMIND_MODEL_GENERATION_GEOMETRY_CYLINDER_H_

#include <cstddef>
#include <string>

#include "Eigen/Geometry"
#include "deepmind/model_generation/model.h"

namespace deepmind {
namespace lab {
namespace geometry {

// Parameters used to construct surfaces in the shape of a elliptic cylinder
// (defaulting to a regular cylinder width diameter 1 and height 1).
struct Cylinder {
  float width_radius = 0.5f;
  float depth_radius = 0.5f;
  float height = 1.0f;
  // How many angular segments in a quadrant of the cylinder's caps.
  std::size_t num_phi_segments = 4;
  // How many radial segments in the cylinder's caps.
  std::size_t num_radius_segments = 1;
  // How many horizontal segments along the cylinder's body.
  std::size_t num_height_segments = 1;
  // Shader used for the cylinder's surfaces.
  std::string shader_name;
};

// Create a surface in the shape of a cylinder with the parameters provided.
Model::Surface CreateSurface(const Cylinder& cylinder_params);

// Create the locator set for a Cone model with the parameters provided. All
// locators will be translated by the offset position.
Model::LocatorMap CreateLocators(
    const Cylinder& cylinder_params,
    const Eigen::Vector3f& offset = Eigen::Vector3f::Zero());

}  // namespace geometry
}  // namespace lab
}  // namespace deepmind

#endif  // DML_DEEPMIND_MODEL_GENERATION_GEOMETRY_CYLINDER_H_
