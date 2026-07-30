
# Step 1: Base image
FROM gcc:latest

# Working directory
WORKDIR /usr/src/app

# Install required dependencies for MySQL C++ connector
RUN apt-get update && apt-get install -y \
    libmysqlcppconn-dev \
    libmysqlclient-dev \
    mysql-client \
    && rm -rf /var/lib/apt/lists/*

# Copy project files
COPY . .

# Compile C++ code
RUN g++ -o tour_app main.cpp -std=c++11 -lmysqlclient -I/usr/include/mysql

# Command to run application
CMD ["./tour_app"]
