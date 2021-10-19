/*********************************************************************************
* Status Definition file to show errors by Issaka SANFO - EPITA/SE               *
*********************************************************************************/





//Include of head of file
#include "status.h"

/** defined error messages */
static char* msg[] = {
  "",
  "\n\n\nOooh!! File open failed\n\n\n",
  "\n\n\nOooh!! This Start City name doesn\'t exist in the Map file!, try an other name!\n\n\n",
  "\n\n\nOooh!! This Destination City name doesn\'t exist in the Map file!, try an other name!\n\n\n",
  "\n\n\nOooh!! Please, give exactly 2 Arguments: the name of the Fist City and the name of the Goal City\n\n\n",
  "Memory allocation failed",
  "Full structure",
  "Empty structure",
  "Value not found",
  "Value already exists",
  "index out of bounds",
  "unable to perform operation",

  "unknown error"
};

/** get message associated with the given status value (O(1)).
 * @param s the status value
 * @return the associated message
 */
char* message(status s) {
  return (s<0 || s >= ERRUNKNOWN) ? msg[ERRUNKNOWN] : msg[s];
}

