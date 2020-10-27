set(FILES 
    AssetManager.hpp
    StateMachine.hpp
)
set(SUBDIRECTORIES "")

foreach(VAR ${SUBDIRECTORIES})
    add_subdirectory(${VAR})
endforeach()

if(FILES)
    target_sources(${PROJECT_NAME} PRIVATE ${FILES})
endif()
