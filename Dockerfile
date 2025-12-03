FROM gcc:12

WORKDIR /myapp

COPY . .

RUN g++ -o app main.cpp

# Esegui l'app
CMD ["./app"]
