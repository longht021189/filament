cmake_minimum_required(VERSION 3.19)
project(svm)

# ==================================================================================================
# Defines
# ==================================================================================================

set(CMAKE_CXX_STANDARD  14)
set(LOG_PREFIX          "#########")
set(SVM_G_DIR           "/Users/thanhlong/Desktop/Projects/svm/surround-view-monitoring-SDK/core/modules/SVM_lib/graphics")
set(SVM_C_DIR           "/Users/thanhlong/Desktop/Projects/svm/surround-view-monitoring-SDK/core/modules/SVM_lib/common")
set(CV_DIR              "/Users/thanhlong/Desktop/Projects/svm/opencv-4.5.3")
set(GLM_DIR             "/Users/thanhlong/Desktop/Projects/svm/glm")
set(PRJ_NAME            svm)

# ==================================================================================================
# Options
# ==================================================================================================

set(INCLUDE_DIRS        ${GENERATION_ROOT}
                        ${GLM_DIR}
                        ${CV_DIR}/include
                        ${SVM_G_DIR}/include
                        ${SVM_C_DIR}/include)

set(SOURCES             main.cpp
                        ${SVM_C_DIR}/src/ObjBin.cpp
                        ${SVM_G_DIR}/src/texture/ViewTexture.cpp
                        ${SVM_G_DIR}/src/filamentapp/data/CustomCar.cpp
                        ${SVM_G_DIR}/src/filamentapp/data/Render2D.cpp
                        ${SVM_G_DIR}/src/filamentapp/FilamentCamera.cpp
                        ${SVM_G_DIR}/src/filamentapp/IBL.cpp
                        ${SVM_G_DIR}/src/filamentapp/RenderEngine.cpp
                        ${SVM_G_DIR}/src/filamentapp/RenderSamples.cpp
                        ${SVM_G_DIR}/src/filamentapp/RenderType.cpp
                        ${SVM_G_DIR}/src/filamentapp/FilamentAsset.cpp)

set(LINK_LIBS           sample-resources
                        filamentapp)

set(COMPILE_OPS         ${COMPILER_FLAGS})

# ==================================================================================================
# Logs
# ==================================================================================================

message(DEBUG "${LOG_PREFIX} GENERATION_ROOT=${GENERATION_ROOT}")
message(DEBUG "${LOG_PREFIX} COMPILER_FLAGS=${COMPILER_FLAGS}")

# ==================================================================================================
# Build
# ==================================================================================================

include_directories(${INCLUDE_DIRS})
add_executable(${PRJ_NAME} ${SOURCES})
target_link_libraries(${PRJ_NAME} PRIVATE ${LINK_LIBS})
target_compile_options(${PRJ_NAME} PRIVATE ${COMPILE_OPS})
