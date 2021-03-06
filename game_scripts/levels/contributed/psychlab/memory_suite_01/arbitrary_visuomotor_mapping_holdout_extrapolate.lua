--[[ Copyright (C) 2018 Google Inc.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
]]

local factory = require 'levels.contributed.psychlab.factories.arbitrary_visuomotor_mapping_factory'

return factory.createLevelApi{
    -- General kwargs:
    maxStepsOffScreen = 300,

    -- Specific kwargs for this task:
    schema =
      'memory_suite_arbitrary_visuomotor_mapping_holdout_extrapolate.lua',

    -- Critical kwargs defining the training vs. held-out testing protocol.
    dataset = 'brady_konkle_oliva2008',
    dataSubset = 'odd',
    episodeLengthSeconds = 450,
    trialsPerEpisodeCap = 75,
}
