#include "sim.h"
#include "btBulletDynamicsCommon.h"
int main(int argc, char** argv)
{
  int i;
  CSim* sim = new CSim();
  sim->createground();
  sim->createsphere();	
  for (i=0;i<100;i++)
  {
    sim->stepsim();
  }
  delete sim;
}
