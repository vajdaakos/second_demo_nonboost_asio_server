cmake_minimum_required(VERSION 3.12)
project(second_demo_nonboost_asio_server)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(certs)
include_directories(jobfiles)
include_directories(makecerts)

add_executable(second_demo_nonboost_asio_server
        certs/7b4a98ce.0
        certs/dh2048.pem
        certs/server.crt
        certs/server.csr
        certs/server.key
        certs/server.key.secure
        jobfiles/01.sh
        jobfiles/02.sh
        jobfiles/03.sh
        jobfiles/04.sh
        jobfiles/05.sh
        jobfiles/06.sh
        jobfiles/07.sh
        jobfiles/08.sh
        jobfiles/09.sh
        jobfiles/10.sh
        jobfiles/11.sh
        jobfiles/12.sh
        jobfiles/13.sh
        jobfiles/14.sh
        jobfiles/15.sh
        makecerts/7b4a98ce.0
        makecerts/dh2048.pem
        makecerts/makecerts.sh
        makecerts/server.crt
        makecerts/server.csr
        makecerts/server.key
        makecerts/server.key.secure
        Auth_answer_message.cpp
        Auth_answer_message.h
        close_connection.cpp
        close_connection.h
        Connection.cpp
        Connection.h
        Job_send_message.cpp
        Job_send_message.h
        main.cpp
        Message.cpp
        Message.h
        Server.cpp
        Server.h
        Signer_and_verifier.cpp
        Signer_and_verifier.h)



find_package (Threads)
find_package(OpenSSL REQUIRED)
if (OPENSSL_FOUND)
    include_directories(${OPENSSL_INCLUDE_DIR})
endif()


TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        pthread
        crypto
        ${OPENSSL_LIBRARIES}
        )