FROM ubuntu:18.04
LABEL maintainer="Biktyanskiy Vladislav 211-351"

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone 
RUN apt-get update 
RUN apt-get install qt5-default -y 
RUN apt-get install qtbase5-dev -y 
RUN apt-get install qt5-qmake 
RUN apt-get install build-essential -y

WORKDIR /usr/src/
COPY Biktyanskiy_211-351 /usr/src/

RUN qmake -makefile -o Makefile ./echoServer.pro
RUN make
ENTRYPOINT ./echoServer