1\. Khái niệm cơ bản

1.1. Kiến trúc CISC (Complex Instruction Set Computer)

CISC là triết lý thiết kế phần cứng ra đời trong giai đoạn đầu của ngành máy tính, khi bộ nhớ (RAM) còn rất đắt đỏ và chậm chạp, trong khi các trình biên dịch chưa đủ thông minh.Mục tiêu chính của CISC là giảm thiểu số lượng lệnh trong một chương trình bằng cách tích hợp nhiều hành động phức tạp (như truy cập bộ nhớ, tính toán và lưu kết quả) vào trong duy nhất một lệnh. Để làm được điều này, phần cứng của chip CISC phải tích hợp các mạch giải mã vi chương trình (microcode) rất phức tạp để dịch một lệnh lớn thành một chuỗi các thao tác nhỏ bên trong chip.

1.2. Kiến trúc RISC (Reduced Instruction Set Computer)

Ngược lại với CISC, RISC ra đời vào thập niên 1980 dựa trên các nghiên cứu thực nghiệm chỉ ra rằng: khoảng 80% chương trình máy tính chỉ sử dụng 20% số lệnh cơ bản của vi xử lý.Triết lý của RISC là đơn giản hóa tập lệnh, tập trung vào các lệnh cơ bản, có kích thước cố định và chỉ thực hiện một tác vụ duy nhất trong một chuỗi chu kỳ xung nhịp (thường là 1 chu kỳ). RISC loại bỏ việc cho phép các lệnh tính toán truy cập trực tiếp vào bộ nhớ; thay vào đó, nó sử dụng kiến trúc Load/Store nghiêm ngặt. Việc đơn giản hóa này giúp phần cứng chạy nhanh hơn, tạo điều kiện cho kỹ thuật đường ống (pipelining) hoạt động tối ưu.

2.Ưu điểm

2.1. Kiến trúc CISC

- Ưu điểm:

  - Tiết kiệm bộ nhớ: Do một lệnh CISC có thể thực hiện một chuỗi thao tác phức tạp, kích thước file thực thi (mã máy) của chương trình rất nhỏ gọn.

  - Thân thiện với lập trình viên và trình biên dịch: Trình biên dịch không cần tốn nhiều công sức để phân rã các tác vụ toán học cao cấp thành nhiều lệnh nhỏ. Lập trình bằng ngôn ngữ Assembly trên CISC cũng trực quan hơn.

  - Tương thích ngược tốt: Kiến trúc x86 của CISC có lịch sử lâu đời, giúp các phần mềm cũ vận hành mượt mà trên phần cứng mới mà không cần biên dịch lại.

- Nhược điểm:

  - Phần cứng quá phức tạp: Việc tích hợp bộ giải mã vi chương trình (microcode) khiến transistor phải dành nhiều diện tích cho việc quản lý lệnh thay vì tính toán thực tế.

  - Thời gian thực thi lệnh không đồng đều: Do độ dài và độ phức tạp của lệnh khác nhau, một lệnh CISC có thể mất từ 1 đến nhiều chu kỳ xung nhịp để hoàn thành, gây khó khăn cho việc tối ưu hóa xung nhịp tổng thể.

  - Tỏa nhiệt và tiêu thụ điện năng lớn: Khối phần cứng cồng kềnh khiến các chip CISC luôn gặp thách thức lớn về mặt nhiệt lượng.

2.2. Kiến trúc RISC

- Ưu điểm:

  - Tốc độ thực thi nhanh: Mỗi lệnh đều đơn giản và hầu hết được thực hiện trong đúng 1 chu kỳ xung nhịp, giúp tăng tốc độ xử lý tổng thể của CPU.

  - Thiết kế phần cứng tối giản: Nhờ loại bỏ bộ giải mã phức tạp, chip RISC tốn ít transistor hơn, kích thước die chip nhỏ hơn, giúp giảm chi phí sản xuất.

  - Hiệu suất năng lượng vượt trội: Cấu trúc đơn giản giúp chip RISC tiêu thụ cực kỳ ít điện năng và tỏa nhiệt thấp.

  - Tối ưu hóa đường ống (Pipelining): Vì tất cả các lệnh có kích thước bằng nhau và thời gian thực thi như nhau, việc xếp chồng các lệnh để xử lý song song (pipelining) đạt hiệu suất gần như hoàn hảo.

- Nhược điểm:

  - Kích thước chương trình lớn: Do mỗi lệnh chỉ làm một việc nhỏ, trình biên dịch phải sinh ra rất nhiều dòng lệnh để hoàn thành một tác vụ, dẫn đến việc tốn bộ nhớ lưu trữ chương trình (Flash/RAM).

  - Phụ thuộc nặng nề vào trình biên dịch: Trình biên dịch phải cực kỳ thông minh để sắp xếp và tối ưu hóa các lệnh đơn lẻ nhằm tránh hiện tượng nghẽn đường ống (pipeline hazards).

  - Tốc độ truy cập bộ nhớ là điểm nghẽn: Việc liên tục phải nạp lệnh từ RAM/Cache vào CPU do số lượng lệnh nhiều đòi hỏi hệ thống bus và bộ nhớ đệm phải có băng thông rất lớn.

3\. So sánh CISC và RISC

<table>
<colgroup>
<col style="width: 15%" />
<col style="width: 41%" />
<col style="width: 43%" />
</colgroup>
<thead>
<tr class="header">
<th><strong>Tiêu chí so sánh</strong></th>
<th><strong>Kiến trúc CISC</strong></th>
<th><strong>Kiến trúc RISC</strong></th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td><strong>Cấu trúc tập lệnh</strong></td>
<td>Số lượng lệnh lớn, độ dài lệnh thay đổi. Nhiều chế độ địa chỉ phức tạp.</td>
<td>Số lượng lệnh hạn chế, độ dài lệnh cố định. Rất ít chế độ địa chỉ.</td>
</tr>
<tr class="even">
<td><strong>Thao tác với bộ nhớ</strong></td>
<td>Cho phép các lệnh toán học/logic thao tác trực tiếp trên các ô nhớ (Memory-to-Memory).</td>
<td>Chỉ sử dụng lệnh LOAD và STORE để tương tác với bộ nhớ; các lệnh toán học chỉ thực thi trên thanh ghi (Register-to-Register).</td>
</tr>
<tr class="odd">
<td><strong>Tốc độ xử lý</strong></td>
<td>Số chu kỳ trên mỗi lệnh (CPI) thay đổi (từ 1 đến nhiều chu kỳ). Tần số xung nhịp bị giới hạn do mạch logic phức tạp.</td>
<td>Hầu hết các lệnh thực thi trong 1 chu kỳ. Khả năng đẩy xung nhịp lên rất cao dễ dàng hơn.</td>
</tr>
<tr class="even">
<td><strong>Kích thước chương trình</strong></td>
<td>Nhỏ gọn, tiết kiệm không gian lưu trữ bộ nhớ.</td>
<td>Lớn, tốn nhiều không gian bộ nhớ do phải phân rã lệnh.</td>
</tr>
<tr class="odd">
<td><strong>Hệ thống thanh ghi</strong></td>
<td>Số lượng thanh ghi đa năng ít (thường từ 8 đến 16 thanh ghi).</td>
<td>Số lượng thanh ghi đa năng rất lớn (thường từ 32 thanh ghi trở lên).</td>
</tr>
<tr class="even">
<td><strong>Độ phức tạp phần cứng</strong></td>
<td>Tập trung vào phần cứng (Hardware-centric). Bộ giải mã microcode phức tạp, chiếm nhiều transistor.</td>
<td>Tập trung vào phần mềm/trình biên dịch (Software-centric). Phần cứng đơn giản, mạch điều khiển dạng cứng.</td>
</tr>
<tr class="odd">
<td><strong>Ứng dụng thực tế</strong></td>
<td><p>Thống trị trong thế giới máy tính cá nhân (PC), Laptop, Máy chủ (Server).</p>
<p><em>Ví dụ: Intel x86/x64, AMD64.</em></p></td>
<td><p>Thống trị trong thiết bị di động, siêu máy tính và hệ thống nhúng.</p>
<p><em>Ví dụ: ARM (Cortex-M/A), Apple Silicon (M-series), RISC-V, MIPS.</em></p></td>
</tr>
</tbody>
</table>

4\. Nêu **quan điểm cá nhân**: Trong bối cảnh phát triển hệ thống nhúng hiện nay, kiến trúc nào phù hợp hơn? Vì sao?

Trong bối cảnh phát triển của các hệ thống nhúng hiện nay — đặc biệt là sự bùng nổ của IoT, thiết bị đeo thông minh (Wearables), Edge AI, và các dòng vi điều khiển công nghiệp, em nghĩ rằng: Kiến trúc RISC phù hợp hơn so với CISC bởi các nguyên nhân sau:

4.1. Yêu cầu tối nghiêm ngặt về hiệu suất năng lượng

Phần lớn các hệ thống nhúng hiện nay vận hành bằng pin, năng lượng mặt trời hoặc yêu cầu hoạt động liên tục trong nhiều năm mà không cần bảo trì (ví dụ: các node cảm biến không dây). Do đó, lượng điện năng tiêu thụ tính bằng mili-watt hoặc micro-watt là yếu tố then chốt.

- RISC với cấu trúc phần cứng tối giản, không tốn năng lượng cho bộ giải mã vi chương trình cồng kềnh, mang lại hiệu suất trên mỗi watt cực cao, điều mà CISC x86 không thể nào đạt được.

4.2. Chi phí sản xuất và kích thước vật lý (Cost & Form Factor)

Thiết bị nhúng thường được sản xuất hàng loạt với số lượng từ hàng nghìn đến hàng triệu bản, yêu cầu giá thành trên mỗi chip phải cực kỳ rẻ (đôi khi chỉ dưới 1 USD).

- Do số lượng transistor ít hơn, diện tích đế silicon của chip RISC nhỏ hơn rất nhiều so với CISC. Điều này giúp hạ giá thành sản xuất xuống mức tối thiểu và cho phép đóng gói chip thành các kích thước siêu nhỏ, phù hợp với các bo mạch nhúng có không gian giới hạn.

4.3. Tính thời gian thực

Trong hệ thống nhúng (đặc biệt là hệ thống nhúng điều khiển tự động hóa, xe tự hành, thiết bị y tế), tính đáp ứng thời gian thực (Real-time) là bắt buộc. Việc tính toán chính xác thời gian thực thi của một đoạn mã đóng vai trò quyết định.

- Với RISC, do độ dài lệnh cố định và hầu hết thực thi trong 1 chu kỳ, các kỹ sư nhúng có thể dễ dàng tính toán, dự đoán và kiểm soát chính xác độ trễ (latency) của hệ thống khi xảy ra ngắt (interrupt).

- Ngược lại, tính chất độ dài lệnh thay đổi của CISC khiến việc thiết kế hệ thống thời gian thực cứng (Hard Real-time) trở nên vô cùng phức tạp.

4.4. Sự trỗi dậy mạnh mẽ của kiến trúc mở RISC-V

Hiện nay, xu hướng dịch chuyển sang kiến trúc mã nguồn mở RISC-V (một nhánh thuần RISC) đang tạo ra một làn sóng cách mạng trong ngành hệ thống nhúng. RISC-V cho phép các kỹ sư, trường đại học và doanh nghiệp tùy biến sâu sắc tập lệnh theo nhu cầu cụ thể của ứng dụng (ví dụ: thêm các tập lệnh tăng tốc toán học cho TinyML) mà không phải trả phí bản quyền đắt đỏ cho ARM hay Intel.
