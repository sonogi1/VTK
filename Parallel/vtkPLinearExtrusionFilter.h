/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkPLinearExtrusionFilter.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


Copyright (c) 1993-2001 Ken Martin, Will Schroeder, Bill Lorensen 
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

 * Neither name of Ken Martin, Will Schroeder, or Bill Lorensen nor the names
   of any contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

 * Modified source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/
// .NAME vtkPLinearExtrusionFilter - Subclass that handles piece invariance.
// .SECTION Description
// vtkPLinearExtrusionFilter is a parallel version of vtkLinearExtrusionFilter.

// .SECTION See Also
// vtkLinearExtrusionFilter

#ifndef __vtkPLinearExtrusionFilter_h
#define __vtkPLinearExtrusionFilter_h

#include "vtkLinearExtrusionFilter.h"

class VTK_PARALLEL_EXPORT vtkPLinearExtrusionFilter : public vtkLinearExtrusionFilter 
{
public:
  vtkTypeMacro(vtkPLinearExtrusionFilter,vtkLinearExtrusionFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Create an object with PieceInvariant off.
  static vtkPLinearExtrusionFilter *New();

  // To get piece invariance, this filter has to request an 
  // extra ghost level.  Since piece invariance is not very 
  // important for this filter,  it is optional.  Without invariance,
  // Internal surfaces will be generated.  These surface
  // Are hidden by the normal surface generated by this filter.
  // By default, PieceInvariance is off.
  vtkSetMacro(PieceInvariant, int);
  vtkGetMacro(PieceInvariant, int);
  vtkBooleanMacro(PieceInvariant, int);

protected:
  vtkPLinearExtrusionFilter();
  ~vtkPLinearExtrusionFilter() {};
  vtkPLinearExtrusionFilter(const vtkPLinearExtrusionFilter&);
  void operator=(const vtkPLinearExtrusionFilter&);

  void Execute();
  void ComputeInputUpdateExtents(vtkDataObject *output);

  int PieceInvariant;
};

#endif
