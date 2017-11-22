CC=gcc
LD=ld
LDFILE=boot.ld # �ϥΤW�����Ѫ��s���}�� boot.ld
OBJCOPY=objcopy

all: boot.img

# Step 1: gcc �ե� as �N boot.S �sĶ���ت��ɮ� boot.o
boot.o: boot.S
	$(CC) -c boot.S

# Step 2: ld �եγs���}�� solrex_x86.ld �N boot.o �s�����i������ boot.elf
boot.elf: boot.o
	$(LD) boot.o -o boot.elf -e c -T$(LDFILE)

# Step 3: objcopy ���� boot.elf ���S���Ϊ� section(.pdr,.comment,.note),
# strip ���Ҧ��Ÿ���T�A��X���G�i���ɮ� boot.bin �C
boot.bin : boot.elf
	@$(OBJCOPY) -R .pdr -R .comment -R.note -S -O binary boot.elf boot.bin

 # Step 4: �ͦ��i�Ұʳn���蹳�C
 boot.img: boot.bin
	@dd if=boot.bin of=boot.img bs=512 count=1 #�� boot.bin �ͦ��蹳�ɲĤ@�Ӻϰ�
	# �b bin �ͦ����蹳�ɫ�ɤW�ťաA�̫ᦨ���X�A�j�p���n���蹳
	@dd if=/dev/zero of=boot.img skip=1 seek=1 bs=512 count=2879

clean:
	@rm -rf boot.o boot.elf boot.bin boot.img