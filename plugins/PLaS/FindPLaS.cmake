# Needs environmental variables
#   PLAS_DIR
# Sets
#   PLAS_INCLUDE_DIR
#   PLAS_LIBRARY
#   CF_HAVE_PLAS

SET_TRIAL_INCLUDE_PATH ("") # clear include search path
SET_TRIAL_LIBRARY_PATH ("") # clear library search path

IF ( EXISTS ${PLAS_DIR} )
  ADD_TRIAL_INCLUDE_PATH( ${PLAS_DIR} )
  ADD_TRIAL_INCLUDE_PATH( ${PLAS_DIR}/include )
  ADD_TRIAL_LIBRARY_PATH( ${PLAS_DIR} )
  ADD_TRIAL_LIBRARY_PATH( ${PLAS_DIR}/lib )
ENDIF()

IF ( EXISTS $ENV{PLAS_DIR} )
  ADD_TRIAL_INCLUDE_PATH( $ENV{PLAS_DIR}/include )
  ADD_TRIAL_LIBRARY_PATH( $ENV{PLAS_DIR}/lib )
ENDIF()

FIND_PATH(PLAS_INCLUDE_DIR plasinterface.h ${TRIAL_INCLUDE_PATHS} NO_DEFAULT_PATH)
FIND_PATH(PLAS_INCLUDE_DIR plasinterface.h)

FIND_LIBRARY(PLAS_LIBRARY plas ${TRIAL_LIBRARY_PATHS} NO_DEFAULT_PATH)
FIND_LIBRARY(PLAS_LIBRARY plas )

IF(PLAS_INCLUDE_DIR AND PLAS_LIBRARY)
  SET ( CF_HAVE_PLAS 1 )
ELSE()
  SET ( CF_HAVE_PLAS 0 )
ENDIF()

MARK_AS_ADVANCED (
  PLAS_LIBRARY
  PLAS_INCLUDE_DIR
  CF_HAVE_PLAS
)

LOG ( "CF_HAVE_PLAS: [${CF_HAVE_PLAS}]" )
IF(CF_HAVE_PLAS)
  LOG ( "  PLAS_INCLUDE_DIR: [${PLAS_INCLUDE_DIR}]" )
  LOG ( "  PLAS_LIBRARY:     [${PLAS_LIBRARY}]" )
ENDIF(CF_HAVE_PLAS)

