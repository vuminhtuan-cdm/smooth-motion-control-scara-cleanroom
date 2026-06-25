% DỌN DẸP BỘ NHỚ TRƯỚC KHI CHẠY
clear; clc; close all;

% CẤU HÌNH CỔNG SERIAL
comPort = 'COM11'; 
baudRate = 115200;

try
    arduino = serialport(comPort, baudRate);
    configureTerminator(arduino, "LF"); % Đọc dữ liệu theo từng dòng (xuống dòng)
    flush(arduino); % Xóa dữ liệu rác ban đầu trong bộ đệm
    fprintf('Kết nối thành công với %s!\n', comPort);
catch
    error('Không kết nối được với cổng %s. Hãy kiểm tra lại dây cáp hoặc cổng COM!', comPort);
end

% CẤU HÌNH ĐỒ THỊ
figure('Name', 'Real-time Motor Speed Log', 'NumberTitle', 'off');
hPlot = plot(NaN, NaN, 'LineWidth', 2, 'Color', [0 0.4470 0.7410]); % Đường vẽ màu xanh dương
grid on;
xlabel('Time Step (Samples)');
ylabel('Speed Data (Pulses/20ms)');
title('SCARA Motor Speed Response');

% Các biến lưu trữ dữ liệu để vẽ
dataBuffer = [];
maxSamples = 200; % Đồ thị sẽ hiển thị tối đa 200 điểm gần nhất 

% VÒNG LẶP ĐỌC DỮ LIỆU 
fprintf('Đang đọc dữ liệu... Bấm nút Tắt cửa sổ đồ thị để dừng.\n');

% Vòng lặp sẽ chạy liên tục cho đến khi tắt cái bảng đồ thị đi
while ishandle(hPlot)
    % Kiểm tra xem có dữ liệu mới từ Arduino gửi về không
    if arduino.NumBytesAvailable > 0
        % Đọc một dòng dữ liệu 
        dataStr = readline(arduino);
        
        % Chuyển chữ thành số
        dataNum = str2double(dataStr);
        
        % Nếu chuyển thành công và là số hợp lệ thì lưu lại
        if ~isnan(dataNum)
            dataBuffer = [dataBuffer; dataNum];
            
            % Nếu dữ liệu quá dài thì xóa điểm cũ nhất đi để đồ thị cuộn lại
            if length(dataBuffer) > maxSamples
                dataBuffer(1) = [];
            end
            
            % Cập nhật lại đường vẽ trên đồ thị
            set(hPlot, 'XData', 1:length(dataBuffer), 'YData', dataBuffer);
            drawnow; % Lệnh ép MATLAB vẽ ngay lập tức lên màn hình
        end
    end
end

% ĐÓNG CỔNG KẾT NỐI KHI TẮT ĐỒ THỊ 
clear arduino;
fprintf('Đã đóng kết nối an toàn.\n');