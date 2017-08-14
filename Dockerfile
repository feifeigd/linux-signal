
FROM alpine

RUN apk --no-cache add libstdc++

#STOPSIGNAL SIGTERM

CMD ["/linux-signal"]
