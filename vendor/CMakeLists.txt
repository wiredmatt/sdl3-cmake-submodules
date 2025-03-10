set(SDL_TEST OFF)
add_subdirectory(SDL EXCLUDE_FROM_ALL)
add_subdirectory(SDL_image EXCLUDE_FROM_ALL)
add_subdirectory(SDL_ttf EXCLUDE_FROM_ALL)
add_subdirectory(SDL_mixer EXCLUDE_FROM_ALL)

add_library(vendor INTERFACE)
target_link_libraries(
    vendor INTERFACE 
    SDL3_image::SDL3_image 
    SDL3_ttf::SDL3_ttf 
    SDL3_mixer::SDL3_mixer
    SDL3::SDL3
)