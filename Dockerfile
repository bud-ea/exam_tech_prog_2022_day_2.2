FROM ubuntu:18.04

LABEL maintainer="Georgy Bubenok"

COPY exam_tech_prog_2022_day_2.2 /211-351_Bubenok

WORKDIR /211-351_Bubenok

RUN apt-get update
RUN apt-get install qt5-default -y
RUN apt-get install qtbase5-dev -y
RUN apt-get install qt5-qmake
RUN apt-get install build-essential -y

RUN qmake echoServer.pro
RUN make

ENTRYPOINT ["./echoServer"]
CMD [""]

