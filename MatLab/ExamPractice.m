y = fft2(zebra);
image(256*log(abs(y))/max(max(log(abs(y)))))

% Low pass filter

mask = zeros(450,800);
mask(1:30,1:30)=1;
mask(1:30,226:256)=1;
mask(226:256,1:30)=1;
mask(226:256,226:256)=1;
image(256*mask)

y2 = y .* mask;
z=ifft2(y2);
image(256*abs(z)/max(max(abs(z))))


% High pass filter 

mask = 1-mask;
y2 = y .* mask;
z = ifft2(y2);
image(256*abs(z)/max(max(abs(z))))

% create mask 3

mask = createMask3(mask, y, 4)
image(256*mask)

% open in seperate window
figure, image(256*log(abs(y))/max(max(log(abs(y)))))

% plot

surf(256*abs(y)/max(max(abs(y))))?

surf(256*log(abs(y))/max(max(log(abs(y)))))?