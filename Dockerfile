FROM ubuntu:20.04
RUN apt-get update && apt-get install -y make clang wget gnupg \
    && rm -rf /var/lib/apt/lists/*

# install gsl
COPY gsl_key.txt /opt
RUN cd /opt \
    && wget ftp://ftp.gnu.org/gnu/gsl/gsl-2.7.tar.gz \
    && wget ftp://ftp.gnu.org/gnu/gsl/gsl-2.7.tar.gz.sig \
    && gpg --import gsl_key.txt \
    && gpg --verify gsl-2.7.tar.gz.sig \
    && tar xfv gsl-2.7.tar.gz \
    && cd gsl-2.7 \
    && ./configure \
    && make \
    && make install \
    && cd /

# install cuba
COPY Cuba-4.2.1.md5 /opt
RUN cd /opt \
    && wget http://www.feynarts.de/cuba/Cuba-4.2.1.tar.gz \
    && md5sum -c Cuba-4.2.1.md5 \
    && tar xfv Cuba-4.2.1.tar.gz \
    && cd Cuba-4.2.1 \
    && ./configure \
    && make \
    && make install \
    && cd /

# build
WORKDIR cuboids/
COPY include include
COPY src src
COPY Makefile .
RUN make release

# copy input files
COPY excludedVolumeCoefficients excludedVolumeCoefficients
COPY input/config_cuboid.txt .
ENV LD_LIBRARY_PATH=/usr/local/lib

CMD ./run config_cuboid.txt