cmake_minimum_required(VERSION 3.5)
project(TweetSentimentalAnalysis LANGUAGES CXX)
set (EXE_NAME TweetSentimentalAnalysis)

# input files
set (input01 "TestData/dev-train-data.csv")
set (input02 "TestData/dev-train-target.csv")

set (input03 "TestData/dev-test-data.csv")
set (input04 "TestData/dev-test-target.csv")

# atually an output
set (input05 "TestData/results.csv")

# copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04 input05)
    configure_file(${file} ${file} COPYONLY)
endforeach()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${EXE_NAME} main.cpp
    sentementalanalysis.cpp sentementalanalysis.h
    DataStructures/dsstring.cpp DataStructures/dsstring.h
    DataStructures/dsvector.h)

include(GNUInstallDirs)
install(TARGETS TweetSentimentalAnalysis
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
