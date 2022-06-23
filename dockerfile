FROM ubuntu:18.04

LABEL maintainer="Drozhilkin Vadim"

COPY exam_tech_prog_2022_day_2.2 /211-351_Drojilkin

WORKDIR /211-351_Drozhilkin

RUN apt-get update
RUN apt-get install qt5-default -y
RUN apt-get install qtbase5-dev -y
RUN apt-get install qt5-qmake
RUN apt-get install build-essential -y

RUN qmake echoServer.pro
RUN make

ENTRYPOINT ["./echoServer"]
CMD [""]

