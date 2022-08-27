cmake_minimum_required(VERSION 3.15)

get_filename_component(project_folder_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${project_folder_name})

add_subdirectory(3rd-party)

add_executable(${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

function(aux_include_directory dir variable)
    file(GLOB_RECURSE temp_list {dir}/*.h)
    set(result "")
    foreach(file_path ${temp_list})
        get_filename_component(dir_path ${file_path} PATH)
        set(result ${result} ${dir_path})
    endforeach()
    list(REMOVE_DUPLICATES dir_list)
    set(${variable} ${result})
endfunction()

aux_include_directory(sources header_dir_list)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${header_dir_list}
)

aux_source_directory(sources sources_list)

target_sources(
    ${PROJECT_NAME}
    PUBLIC
    ${sources_list}
)

target_link_libraries(${PROJECT_NAME} PRIVATE ImGui-SFML::ImGui-SFML)
