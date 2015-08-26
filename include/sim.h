#include "btBulletDynamicsCommon.h"
#include <stdio.h>
class CSim {
  private:
  // Variables
  btDefaultCollisionConfiguration* collisionConfiguration;
  btCollisionDispatcher* dispatcher;
  btBroadphaseInterface* overlappingPairCache;
  btSequentialImpulseConstraintSolver* solver;
  btDiscreteDynamicsWorld* dynamicsWorld;
  btAlignedObjectArray<btCollisionShape*> collisionShapes;
  int i;
  //Functions
  public:
  CSim();
  ~CSim();
  void createground();
  void createsphere();
  void stepsim();
};
