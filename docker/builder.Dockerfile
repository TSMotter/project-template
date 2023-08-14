ARG base_img=gcc
ARG base_tag=9.5.0-bullseye
FROM --platform=linux/amd64 ${base_img}:${base_tag} AS builder-install

# ARG base_img=alpine
# ARG base_tag=3.14
# FROM --platform=linux/amd64 ${base_img}:${base_tag} AS builder-install

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# Install 'basic packages'
RUN apt-get update --fix-missing && apt-get -y upgrade
RUN apt-get install -y \
    apt-utils \
    curl \
    build-essential \
    gcc \
    g++-multilib \
    locales \
    make \
    ruby \
    gcovr \
    wget \
    && rm -rf /var/lib/apt/lists/*

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# Install specific version of cmake
ARG cmake_version=3.22
ARG cmake_build=0
ARG cmake_revision=${cmake_version}.${cmake_build}
RUN wget https://cmake.org/files/v${cmake_version}/cmake-${cmake_revision}.tar.gz && \
    tar -xzvf cmake-${cmake_revision}.tar.gz && \
    cd cmake-${cmake_revision} && \
    ./bootstrap && \
    make && \
    make install && \
    cd .. && \
    rm -rf cmake-${cmake_revision}*

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# Install google-test
RUN apt-get update && \
    apt-get install -y cmake && \
    rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/google/googletest.git /opt/googletest && \
    cd /opt/googletest && \
    mkdir build && \
    cd build && \
    cmake .. -DBUILD_SHARED_LIBS=ON -DINSTALL_GTEST=ON -DCMAKE_INSTALL_PREFIX:PATH=/usr && \
    make && \
    make install

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# Install specific version of clang tools
ARG base_tag=bullseye
ARG llvm_version=14
RUN apt-get update --fix-missing && apt-get -y upgrade
RUN apt-get install -y --no-install-recommends \
    gnupg2 \
    gnupg-agent \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

RUN curl --fail --silent --show-error --location https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
RUN echo "deb http://apt.llvm.org/$base_tag/ llvm-toolchain-$base_tag-$llvm_version main" >> /etc/apt/sources.list.d/llvm.list

RUN apt-get update --fix-missing && apt-get -y upgrade
RUN apt-get install -y --no-install-recommends \
    clang-format-${llvm_version} \
    clang-tidy-${llvm_version} \
    && rm -rf /var/lib/apt/lists/*

RUN ln -s /usr/bin/clang-format-${llvm_version} /usr/local/bin/clang-format
RUN ln -s /usr/bin/clang-tidy-${llvm_version} /usr/local/bin/clang-tidy

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# Set up environment
ENV LANG='en_US.UTF-8' LANGUAGE='en_US:en' LC_ALL='en_US.UTF-8'

RUN echo 'en_US.UTF-8 UTF-8' > /etc/locale.gen && /usr/sbin/locale-gen
RUN echo "alias ll='ls -laGFh'" >> /root/.bashrc

VOLUME ["/builder/mnt"]
WORKDIR /builder/mnt

RUN apt remove -y \
    wget