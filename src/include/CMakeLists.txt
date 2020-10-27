set(FILES 
    config.hpp
    State.hpp
    Game.hpp
    GameInfo.hpp
)
set(SUBDIRECTORIES "GameData")

foreach(VAR ${SUBDIRECTORIES})
    add_subdirectory(${VAR})
endforeach()

if(FILES)
    target_sources(${PROJECT_NAME} PRIVATE ${FILES})
endif()
