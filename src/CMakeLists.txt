set(FILES 
    main.cpp
)
set(SUBDIRECTORIES "include" "GameData" "States")

add_executable(${PROJECT_NAME} ${FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system ${CONAN_LIBS})
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

foreach(VAR ${SUBDIRECTORIES})
    add_subdirectory(${VAR})
endforeach()
