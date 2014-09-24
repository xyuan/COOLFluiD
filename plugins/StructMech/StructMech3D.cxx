#include "StructMech/StructMech.hh"
#include "Framework/State.hh"
#include "StructMech3D.hh"
#include "Environment/ObjectProvider.hh"

//////////////////////////////////////////////////////////////////////////////

using namespace COOLFluiD::Framework;

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace Physics {

    namespace StructMech {

//////////////////////////////////////////////////////////////////////////////

Environment::ObjectProvider<StructMech3D, PhysicalModelImpl, StructMechModule, 1> heat3DProvider("StructMech3D");

//////////////////////////////////////////////////////////////////////////////

StructMech3D::StructMech3D(const std::string& name)
  : StructMechPhysicalModel(name)
{
}

//////////////////////////////////////////////////////////////////////////////

StructMech3D::~StructMech3D()
{
}

//////////////////////////////////////////////////////////////////////////////

void StructMech3D::configure ( Config::ConfigArgs& args )
{
  StructMechPhysicalModel::configure(args);

  /// @note Should be here, but is not yet being used.
  _jacobians = std::vector<RealMatrix>(getDimension());
  for (CFuint i = 0; i < getDimension(); ++i) {
    _jacobians[i] = RealMatrix(getNbEquations(), getNbEquations());
    _jacobians[i] = 0.0;
  }

}

//////////////////////////////////////////////////////////////////////////////

CFuint StructMech3D::getDimension() const
{
  return 3;
}

//////////////////////////////////////////////////////////////////////////////

CFuint StructMech3D::getNbEquations() const
{
  return 3;
}

//////////////////////////////////////////////////////////////////////////////

bool StructMech3D::validate(const State& state) const
{
  return true;
}

//////////////////////////////////////////////////////////////////////////////

    } // namespace StructMech

  } // namespace Physics

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////