cmake_minimum_required(VERSION 3.5)

project(TweetSentimentalAnalysis LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TweetSentimentalAnalysis main.cpp
    tweetdatacleaner.h tweetdatacleaner.cpp
    DataStructures/dsvector.h
    DataStructures/dsstring.h DataStructures/dsstring.cpp)

include(GNUInstallDirs)
install(TARGETS TweetSentimentalAnalysis
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
