FROM ubuntu:18.04
LABEL maintainer="Mikanev Artem"

      ENV TZ=Europe/Moscow 
      RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone 
      RUN apt-get update 
      RUN apt-get install qt5-default -y 
      RUN apt-get install qtbase5-dev -y 
      RUN apt-get install qt5-qmake 
      RUN apt-get install build-essential -y 

COPY . /root/Mikanev_211_351/
WORKDIR /root/Mikanev_211_351/

RUN qmake echoServer.pro && \
    make

CMD ./echoServer