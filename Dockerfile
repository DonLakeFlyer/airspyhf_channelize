FROM auterion/ubuntu-mavsdk:v0.44.0 as build-stage

WORKDIR /matlab-extern
COPY matlab-extern .
WORKDIR /airspyhf_channelize
COPY udp.cpp udp.h .
WORKDIR /airspyhf_channelize/codegen/exe/testChannelize
COPY codegen/exe/testChannelize .
RUN make -j12 -f testChannelize_rtw.mk

FROM arm64v8/ubuntu as release-stage

ARG DEBIAN_FRONTEND=noninteractive

# MAVSDK dependencies
RUN apt-get update \
    && apt-get clean \
    && apt-get install -y --no-install-recommends libgomp1 airspyhf netcat \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY --from=build-stage /airspyhf_channelize/testChannelize /app/

ENTRYPOINT [ "/app/testChannelize" ]
