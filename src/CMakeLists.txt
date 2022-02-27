
################################
# setting path to include files 
################################

include_directories( 
    ${CMAKE_SOURCE_DIR}/include
) 

add_compile_options(-ggdb)

######################
# compiled libraries
######################

#add_library(booger SHARED booger.cpp)

######################
# executables 
######################

add_executable(${PROJECT_NAME} main.c parse.c)
#target_link_libraries( ${PROJECT_NAME} PUBLIC booger)
#target_link_options(${PROJECT_NAME} PUBLIC "-Wl,-rpath,${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")

######################
# installation 
######################

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
#nstall(TARGETS booger LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}) # dynamic
#install(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}) # static
