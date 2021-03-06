// Copyright (C) 2012 von Karman Institute for Fluid Dynamics, Belgium
//
// This software is distributed under the terms of the
// GNU Lesser General Public License version 3 (LGPLv3).
// See doc/lgpl.txt and doc/gpl.txt for the license text.

#ifndef COOLFluiD_Numerics_NewtonMethod_TwoLayerUnSetup_hh
#define COOLFluiD_Numerics_NewtonMethod_TwoLayerUnSetup_hh

//////////////////////////////////////////////////////////////////////////////

#include "NewtonIteratorData.hh"
#include "Framework/DataSocketSink.hh"
#include "Framework/Storage.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace Numerics {

    namespace NewtonMethod {

//////////////////////////////////////////////////////////////////////////////

/// This class represents a NumericalCommand action to be
/// to be executed in order to deallocate data specific to the
/// method to which it belongs.
/// @author Thomas Wuilbaut
/// @author Tiago Quintino
class TwoLayerUnSetup : public NewtonIteratorCom {
public:

  /// Constructor.
  explicit TwoLayerUnSetup(std::string name);
  /// Destructor.
  ~TwoLayerUnSetup();

  /// Returns the DataSocket's that this command needs as sinks
  /// @return a vector of SafePtr with the DataSockets
  std::vector<Common::SafePtr<Framework::BaseDataSocketSink> > needsSockets();

  /// Execute Processing actions
  void execute();

protected:

  /// socket for the past states
  Framework::DataSocketSink<
                            Framework::State*> socket_pastStates;

  /// socket for the inter states
  Framework::DataSocketSink<
                            Framework::State*> socket_interStates;

}; // class Setup

//////////////////////////////////////////////////////////////////////////////

    } // namespace NewtonMethod

  } // namespace Numerics

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////

#endif // COOLFluiD_Numerics_NewtonMethod_TwoLayerUnSetup_hh
