FROM ubuntu:20.04
LABEL maintainer="Mushkin Sergey 211-351"

WORKDIR /usr/src/
COPY ./ /usr/src/

#ENV TZ=Europe/Moscow
#RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone 
RUN apt-get update 

RUN DEBIAN_FRONTEND=noninteractive apt-get install qt5-default -y 
RUN apt-get install qtbase5-dev -y 
RUN apt-get install qt5-qmake 
RUN apt-get install build-essential -y



RUN qmake -makefile -o Makefile echoServer.pro
RUN make
ENTRYPOINT ./echoServer