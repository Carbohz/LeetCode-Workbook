cmake_minimum_required(VERSION 3.12)

project(
  1108DefangingAnIpAddress
  LANGUAGES CXX)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here

  # Let's ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

endif()

# The executable code is here
add_executable(app solution.cpp)

set(MSVC_WARNINGS
/W4 # Baseline reasonable warnings
/WX # Treat warnings as errors
/w14242 # 'identifier': conversion from 'type1' to 'type1', possible loss of data
/w14254 # 'operator': conversion from 'type1:field_bits' to 'type2:field_bits', possible loss of data
/w14263 # 'function': member function does not override any base class virtual member function
/w14265 # 'classname': class has virtual functions, but destructor is not virtual instances of this class may not
        # be destructed correctly
/w14287 # 'operator': unsigned/negative constant mismatch
/we4289 # nonstandard extension used: 'variable': loop control variable declared in the for-loop is used outside
        # the for-loop scope
/w14296 # 'operator': expression is always 'boolean_value'
/w14311 # 'variable': pointer truncation from 'type1' to 'type2'
/w14545 # expression before comma evaluates to a function which is missing an argument list
/w14546 # function call before comma missing argument list
/w14547 # 'operator': operator before comma has no effect; expected operator with side-effect
/w14549 # 'operator': operator before comma has no effect; did you intend 'operator'?
/w14555 # expression has no effect; expected expression with side- effect
/w14619 # pragma warning: there is no warning number 'number'
/w14640 # Enable warning on thread un-safe static member initialization
/w14826 # Conversion from 'type1' to 'type_2' is sign-extended. This may cause unexpected runtime behavior.
/w14905 # wide string literal cast to 'LPSTR'
/w14906 # string literal cast to 'LPWSTR'
/w14928 # illegal copy-initialization; more than one user-defined conversion has been implicitly applied
/w15038 
/permissive- # standards conformance mode for MSVC compiler.
)

set(PROJECT_WARNINGS ${MSVC_WARNINGS})

target_compile_options(app PRIVATE ${PROJECT_WARNINGS})

target_compile_features(app PRIVATE cxx_std_17)
