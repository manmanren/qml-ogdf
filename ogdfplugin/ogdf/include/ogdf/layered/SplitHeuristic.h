/*
 * $Revision: 3210 $
 *
 * last checkin:
 *   $Author: gutwenger $
 *   $Date: 2013-01-15 11:58:53 +0100 (Di, 15. Jan 2013) $
 ***************************************************************/

/** \file
 * \brief Declaration of class SplitHeuristic.
 *
 * \author Andrea Wagner
 *
 * \par License:
 * This file is part of the Open Graph Drawing Framework (OGDF).
 *
 * \par
 * Copyright (C)<br>
 * See README.txt in the root directory of the OGDF installation for details.
 *
 * \par
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * Version 2 or 3 as published by the Free Software Foundation;
 * see the file LICENSE.txt included in the packaging of this file
 * for details.
 *
 * \par
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * \par
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 * \see  http://www.gnu.org/copyleft/gpl.html
 ***************************************************************/

#ifdef _MSC_VER
#pragma once
#endif

#ifndef OGDF_SPLIT_HEURISTIC_H
#define OGDF_SPLIT_HEURISTIC_H


#include <ogdf/basic/EdgeArray.h>
#include <ogdf/layered/CrossingsMatrix.h>
#include <ogdf/simultaneous/TwoLayerCrossMinSimDraw.h>

namespace ogdf {


//! The split heuristic for 2-layer crossing minimization.
class OGDF_EXPORT SplitHeuristic : public TwoLayerCrossMinSimDraw
{
public:
	//! Creates a new instance of the split heuristic.
	SplitHeuristic() { }

	//! Creates a new instance of the split heuristic.
	SplitHeuristic(const SplitHeuristic &crossMin) { }

	//! Returns a new instance of the splitheurisitc with the same option settings.
	TwoLayerCrossMinSimDraw *clone() const { return new SplitHeuristic(*this); }

	//! Initializes crossing minimization for hierarchy \a H.
	void init (const HierarchyLevels &levels);

	//! Calls the split heuristic for level \a L.
	void call (Level &L);

	//! Calls the median heuristic for level \a L (simultaneous drawing).
	void call (Level &L, const EdgeArray<__uint32> *edgeSubGraphs);

	//! Does some clean-up after calls.
	void cleanup ();

private:
	CrossingsMatrix *m_cm;
	Array<node> buffer;

	void recCall(Level&, int low, int high);
};

}// end namespace ogdf

#endif
