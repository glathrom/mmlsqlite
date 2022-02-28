################################
# setting path to include files 
################################

include_directories( 
    ../include 
) 

######################
# target executable
######################


add_executable(testopen testopen.c)
target_link_libraries(testopen PUBLIC sqlite) 
